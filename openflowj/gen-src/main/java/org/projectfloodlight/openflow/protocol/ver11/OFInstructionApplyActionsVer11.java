// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver11;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.List;
import com.google.common.collect.ImmutableList;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFInstructionApplyActionsVer11 implements OFInstructionApplyActions {
    private static final Logger logger = LoggerFactory.getLogger(OFInstructionApplyActionsVer11.class);
    // version: 1.1
    final static byte WIRE_VERSION = 2;
    final static int MINIMUM_LENGTH = 8;

        private final static List<OFAction> DEFAULT_ACTIONS = ImmutableList.<OFAction>of();

    // OF message fields
    private final List<OFAction> actions;
//
    // Immutable default instance
    final static OFInstructionApplyActionsVer11 DEFAULT = new OFInstructionApplyActionsVer11(
        DEFAULT_ACTIONS
    );

    // package private constructor - used by readers, builders, and factory
    OFInstructionApplyActionsVer11(List<OFAction> actions) {
        if(actions == null) {
            throw new NullPointerException("OFInstructionApplyActionsVer11: property actions cannot be null");
        }
        this.actions = actions;
    }

    // Accessors for OF message fields
    @Override
    public OFInstructionType getType() {
        return OFInstructionType.APPLY_ACTIONS;
    }

    @Override
    public List<OFAction> getActions() {
        return actions;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_11;
    }



    public OFInstructionApplyActions.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFInstructionApplyActions.Builder {
        final OFInstructionApplyActionsVer11 parentMessage;

        // OF message fields
        private boolean actionsSet;
        private List<OFAction> actions;

        BuilderWithParent(OFInstructionApplyActionsVer11 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFInstructionType getType() {
        return OFInstructionType.APPLY_ACTIONS;
    }

    @Override
    public List<OFAction> getActions() {
        return actions;
    }

    @Override
    public OFInstructionApplyActions.Builder setActions(List<OFAction> actions) {
        this.actions = actions;
        this.actionsSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_11;
    }



        @Override
        public OFInstructionApplyActions build() {
                List<OFAction> actions = this.actionsSet ? this.actions : parentMessage.actions;
                if(actions == null)
                    throw new NullPointerException("Property actions must not be null");

                //
                return new OFInstructionApplyActionsVer11(
                    actions
                );
        }

    }

    static class Builder implements OFInstructionApplyActions.Builder {
        // OF message fields
        private boolean actionsSet;
        private List<OFAction> actions;

    @Override
    public OFInstructionType getType() {
        return OFInstructionType.APPLY_ACTIONS;
    }

    @Override
    public List<OFAction> getActions() {
        return actions;
    }

    @Override
    public OFInstructionApplyActions.Builder setActions(List<OFAction> actions) {
        this.actions = actions;
        this.actionsSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_11;
    }

//
        @Override
        public OFInstructionApplyActions build() {
            List<OFAction> actions = this.actionsSet ? this.actions : DEFAULT_ACTIONS;
            if(actions == null)
                throw new NullPointerException("Property actions must not be null");


            return new OFInstructionApplyActionsVer11(
                    actions
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader extends AbstractOFMessageReader<OFInstructionApplyActions> {
        @Override
        public OFInstructionApplyActions readFrom(OFMessageReaderContext context, ByteBuf bb) throws OFParseError {
            if(bb.readableBytes() < MINIMUM_LENGTH)
                return null;
            int start = bb.readerIndex();
            // fixed value property type == 4
            short type = bb.readShort();
            if(type != (short) 0x4)
                throw new OFParseError("Wrong type: Expected=OFInstructionType.APPLY_ACTIONS(4), got="+type);
            int length = U16.f(bb.readShort());
            if(length < MINIMUM_LENGTH)
                throw new OFParseError("Wrong length: Expected to be >= " + MINIMUM_LENGTH + ", was: " + length);
            //
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            // pad: 4 bytes
            bb.skipBytes(4);
            List<OFAction> actions = ChannelUtils.readList(context, bb, length - (bb.readerIndex() - start), OFActionVer11.READER);

            OFInstructionApplyActionsVer11 instructionApplyActionsVer11 = new OFInstructionApplyActionsVer11(
                    actions
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", instructionApplyActionsVer11);
            return instructionApplyActionsVer11;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFInstructionApplyActionsVer11Funnel FUNNEL = new OFInstructionApplyActionsVer11Funnel();
    static class OFInstructionApplyActionsVer11Funnel implements Funnel<OFInstructionApplyActionsVer11> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFInstructionApplyActionsVer11 message, PrimitiveSink sink) {
            // fixed value property type = 4
            sink.putShort((short) 0x4);
            // FIXME: skip funnel of length
            // skip pad (4 bytes)
            FunnelUtils.putList(message.actions, sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFInstructionApplyActionsVer11> {
        @Override
        public void write(ByteBuf bb, OFInstructionApplyActionsVer11 message) {
            int startIndex = bb.writerIndex();
            // fixed value property type = 4
            bb.writeShort((short) 0x4);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            // pad: 4 bytes
            bb.writeZero(4);
            ChannelUtils.writeList(bb, message.actions);

            // update length field
            int length = bb.writerIndex() - startIndex;
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFInstructionApplyActionsVer11(");
        b.append("actions=").append(actions);
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFInstructionApplyActionsVer11 other = (OFInstructionApplyActionsVer11) obj;

        if (actions == null) {
            if (other.actions != null)
                return false;
        } else if (!actions.equals(other.actions))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((actions == null) ? 0 : actions.hashCode());
        return result;
    }

}
