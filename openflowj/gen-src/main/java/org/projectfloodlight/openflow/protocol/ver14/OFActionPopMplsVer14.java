// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver14;

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
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFActionPopMplsVer14 implements OFActionPopMpls {
    private static final Logger logger = LoggerFactory.getLogger(OFActionPopMplsVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int LENGTH = 8;

        private final static EthType DEFAULT_ETHERTYPE = EthType.NONE;

    // OF message fields
    private final EthType ethertype;
//
    // Immutable default instance
    final static OFActionPopMplsVer14 DEFAULT = new OFActionPopMplsVer14(
        DEFAULT_ETHERTYPE
    );

    // package private constructor - used by readers, builders, and factory
    OFActionPopMplsVer14(EthType ethertype) {
        if(ethertype == null) {
            throw new NullPointerException("OFActionPopMplsVer14: property ethertype cannot be null");
        }
        this.ethertype = ethertype;
    }

    // Accessors for OF message fields
    @Override
    public EthType getEthertype() {
        return ethertype;
    }

    @Override
    public OFActionType getType() {
        return OFActionType.POP_MPLS;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



    public OFActionPopMpls.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFActionPopMpls.Builder {
        final OFActionPopMplsVer14 parentMessage;

        // OF message fields
        private boolean ethertypeSet;
        private EthType ethertype;

        BuilderWithParent(OFActionPopMplsVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public EthType getEthertype() {
        return ethertype;
    }

    @Override
    public OFActionPopMpls.Builder setEthertype(EthType ethertype) {
        this.ethertype = ethertype;
        this.ethertypeSet = true;
        return this;
    }
    @Override
    public OFActionType getType() {
        return OFActionType.POP_MPLS;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



        @Override
        public OFActionPopMpls build() {
                EthType ethertype = this.ethertypeSet ? this.ethertype : parentMessage.ethertype;
                if(ethertype == null)
                    throw new NullPointerException("Property ethertype must not be null");

                //
                return new OFActionPopMplsVer14(
                    ethertype
                );
        }

    }

    static class Builder implements OFActionPopMpls.Builder {
        // OF message fields
        private boolean ethertypeSet;
        private EthType ethertype;

    @Override
    public EthType getEthertype() {
        return ethertype;
    }

    @Override
    public OFActionPopMpls.Builder setEthertype(EthType ethertype) {
        this.ethertype = ethertype;
        this.ethertypeSet = true;
        return this;
    }
    @Override
    public OFActionType getType() {
        return OFActionType.POP_MPLS;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

//
        @Override
        public OFActionPopMpls build() {
            EthType ethertype = this.ethertypeSet ? this.ethertype : DEFAULT_ETHERTYPE;
            if(ethertype == null)
                throw new NullPointerException("Property ethertype must not be null");


            return new OFActionPopMplsVer14(
                    ethertype
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFActionPopMpls> {
        @Override
        public OFActionPopMpls readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 20
            short type = bb.readShort();
            if(type != (short) 0x14)
                throw new OFParseError("Wrong type: Expected=OFActionType.POP_MPLS(20), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 8)
                throw new OFParseError("Wrong length: Expected=8(8), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            EthType ethertype = EthType.read2Bytes(bb);
            // pad: 2 bytes
            bb.skipBytes(2);

            OFActionPopMplsVer14 actionPopMplsVer14 = new OFActionPopMplsVer14(
                    ethertype
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", actionPopMplsVer14);
            return actionPopMplsVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFActionPopMplsVer14Funnel FUNNEL = new OFActionPopMplsVer14Funnel();
    static class OFActionPopMplsVer14Funnel implements Funnel<OFActionPopMplsVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFActionPopMplsVer14 message, PrimitiveSink sink) {
            // fixed value property type = 20
            sink.putShort((short) 0x14);
            // fixed value property length = 8
            sink.putShort((short) 0x8);
            message.ethertype.putTo(sink);
            // skip pad (2 bytes)
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFActionPopMplsVer14> {
        @Override
        public void write(ByteBuf bb, OFActionPopMplsVer14 message) {
            // fixed value property type = 20
            bb.writeShort((short) 0x14);
            // fixed value property length = 8
            bb.writeShort((short) 0x8);
            message.ethertype.write2Bytes(bb);
            // pad: 2 bytes
            bb.writeZero(2);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFActionPopMplsVer14(");
        b.append("ethertype=").append(ethertype);
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
        OFActionPopMplsVer14 other = (OFActionPopMplsVer14) obj;

        if (ethertype == null) {
            if (other.ethertype != null)
                return false;
        } else if (!ethertype.equals(other.ethertype))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((ethertype == null) ? 0 : ethertype.hashCode());
        return result;
    }

}
