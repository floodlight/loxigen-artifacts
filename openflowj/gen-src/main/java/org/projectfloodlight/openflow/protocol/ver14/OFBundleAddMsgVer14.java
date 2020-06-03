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
import com.google.common.collect.ImmutableSet;
import java.util.List;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFBundleAddMsgVer14 implements OFBundleAddMsg {
    private static final Logger logger = LoggerFactory.getLogger(OFBundleAddMsgVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int MINIMUM_LENGTH = 16;
    // maximum OF message length: 16 bit, unsigned
    final static int MAXIMUM_LENGTH = 0xFFFF;

        private final static long DEFAULT_XID = 0x0L;
        private final static Set<OFBundleFlags> DEFAULT_FLAGS = ImmutableSet.<OFBundleFlags>of();

    // OF message fields
    private final long xid;
    private final BundleId bundleId;
    private final Set<OFBundleFlags> flags;
    private final OFMessage data;
//

    // package private constructor - used by readers, builders, and factory
    OFBundleAddMsgVer14(long xid, BundleId bundleId, Set<OFBundleFlags> flags, OFMessage data) {
        if(bundleId == null) {
            throw new NullPointerException("OFBundleAddMsgVer14: property bundleId cannot be null");
        }
        if(flags == null) {
            throw new NullPointerException("OFBundleAddMsgVer14: property flags cannot be null");
        }
        if(data == null) {
            throw new NullPointerException("OFBundleAddMsgVer14: property data cannot be null");
        }
        this.xid = U32.normalize(xid);
        this.bundleId = bundleId;
        this.flags = flags;
        this.data = data;
    }

    // Accessors for OF message fields
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

    @Override
    public OFType getType() {
        return OFType.BUNDLE_ADD_MESSAGE;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public BundleId getBundleId() {
        return bundleId;
    }

    @Override
    public Set<OFBundleFlags> getFlags() {
        return flags;
    }

    @Override
    public OFMessage getData() {
        return data;
    }

    @Override
    public OFMessage getMessage()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property message not supported in version 1.4");
    }

    @Override
    public List<OFBundleProp> getProperties()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property properties not supported in version 1.4");
    }



    public OFBundleAddMsg.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBundleAddMsg.Builder {
        final OFBundleAddMsgVer14 parentMessage;

        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean bundleIdSet;
        private BundleId bundleId;
        private boolean flagsSet;
        private Set<OFBundleFlags> flags;
        private boolean dataSet;
        private OFMessage data;

        BuilderWithParent(OFBundleAddMsgVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

    @Override
    public OFType getType() {
        return OFType.BUNDLE_ADD_MESSAGE;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFBundleAddMsg.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public BundleId getBundleId() {
        return bundleId;
    }

    @Override
    public OFBundleAddMsg.Builder setBundleId(BundleId bundleId) {
        this.bundleId = bundleId;
        this.bundleIdSet = true;
        return this;
    }
    @Override
    public Set<OFBundleFlags> getFlags() {
        return flags;
    }

    @Override
    public OFBundleAddMsg.Builder setFlags(Set<OFBundleFlags> flags) {
        this.flags = flags;
        this.flagsSet = true;
        return this;
    }
    @Override
    public OFMessage getData() {
        return data;
    }

    /** Custom setter that ensures the BundleAdd message inherits the XID from their
     *  contained message, as per OF Spec 1.4.0:
     *  <p>
     *  7.3.9.6 Adding messages to a bundle
     *  </p><p>
     *     Message added in a bundle should have a unique xid to help matching errors to messages,
     *     and the xid of the bundle add message must be the same.
     *  </p>
     */
    @Override
    public OFBundleAddMsg.Builder setData(OFMessage data) {
        this.data = data;
        this.dataSet = true;
        return setXid(data.getXid());
    }

    @Override
    public OFMessage getMessage()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property message not supported in version 1.4");
    }

    @Override
    public OFBundleAddMsg.Builder setMessage(OFMessage message) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property message not supported in version 1.4");
    }
    @Override
    public List<OFBundleProp> getProperties()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property properties not supported in version 1.4");
    }

    @Override
    public OFBundleAddMsg.Builder setProperties(List<OFBundleProp> properties) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property properties not supported in version 1.4");
    }


        @Override
        public OFBundleAddMsg build() {
                long xid = this.xidSet ? this.xid : parentMessage.xid;
                BundleId bundleId = this.bundleIdSet ? this.bundleId : parentMessage.bundleId;
                if(bundleId == null)
                    throw new NullPointerException("Property bundleId must not be null");
                Set<OFBundleFlags> flags = this.flagsSet ? this.flags : parentMessage.flags;
                if(flags == null)
                    throw new NullPointerException("Property flags must not be null");
                OFMessage data = this.dataSet ? this.data : parentMessage.data;
                if(data == null)
                    throw new NullPointerException("Property data must not be null");

                //
                return new OFBundleAddMsgVer14(
                    xid,
                    bundleId,
                    flags,
                    data
                );
        }

    }

    static class Builder implements OFBundleAddMsg.Builder {
        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean bundleIdSet;
        private BundleId bundleId;
        private boolean flagsSet;
        private Set<OFBundleFlags> flags;
        private boolean dataSet;
        private OFMessage data;

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

    @Override
    public OFType getType() {
        return OFType.BUNDLE_ADD_MESSAGE;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFBundleAddMsg.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public BundleId getBundleId() {
        return bundleId;
    }

    @Override
    public OFBundleAddMsg.Builder setBundleId(BundleId bundleId) {
        this.bundleId = bundleId;
        this.bundleIdSet = true;
        return this;
    }
    @Override
    public Set<OFBundleFlags> getFlags() {
        return flags;
    }

    @Override
    public OFBundleAddMsg.Builder setFlags(Set<OFBundleFlags> flags) {
        this.flags = flags;
        this.flagsSet = true;
        return this;
    }
    @Override
    public OFMessage getData() {
        return data;
    }

    /** Custom setter that ensures the BundleAdd message inherits the XID from their
     *  contained message, as per OF Spec 1.4.0:
     *  <p>
     *  7.3.9.6 Adding messages to a bundle
     *  </p><p>
     *     Message added in a bundle should have a unique xid to help matching errors to messages,
     *     and the xid of the bundle add message must be the same.
     *  </p>
     */
    @Override
    public OFBundleAddMsg.Builder setData(OFMessage data) {
        this.data = data;
        this.dataSet = true;
        return setXid(data.getXid());
    }

    @Override
    public OFMessage getMessage()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property message not supported in version 1.4");
    }

    @Override
    public OFBundleAddMsg.Builder setMessage(OFMessage message) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property message not supported in version 1.4");
    }
    @Override
    public List<OFBundleProp> getProperties()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property properties not supported in version 1.4");
    }

    @Override
    public OFBundleAddMsg.Builder setProperties(List<OFBundleProp> properties) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property properties not supported in version 1.4");
    }
//
        @Override
        public OFBundleAddMsg build() {
            long xid = this.xidSet ? this.xid : DEFAULT_XID;
            if(!this.bundleIdSet)
                throw new IllegalStateException("Property bundleId doesn't have default value -- must be set");
            if(bundleId == null)
                throw new NullPointerException("Property bundleId must not be null");
            Set<OFBundleFlags> flags = this.flagsSet ? this.flags : DEFAULT_FLAGS;
            if(flags == null)
                throw new NullPointerException("Property flags must not be null");
            if(!this.dataSet)
                throw new IllegalStateException("Property data doesn't have default value -- must be set");
            if(data == null)
                throw new NullPointerException("Property data must not be null");


            return new OFBundleAddMsgVer14(
                    xid,
                    bundleId,
                    flags,
                    data
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBundleAddMsg> {
        @Override
        public OFBundleAddMsg readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property version == 5
            byte version = bb.readByte();
            if(version != (byte) 0x5)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_14(5), got="+version);
            // fixed value property type == 34
            byte type = bb.readByte();
            if(type != (byte) 0x22)
                throw new OFParseError("Wrong type: Expected=OFType.BUNDLE_ADD_MESSAGE(34), got="+type);
            int length = U16.f(bb.readShort());
            if(length < MINIMUM_LENGTH)
                throw new OFParseError("Wrong length: Expected to be >= " + MINIMUM_LENGTH + ", was: " + length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            long xid = U32.f(bb.readInt());
            BundleId bundleId = BundleId.read4Bytes(bb);
            // pad: 2 bytes
            bb.skipBytes(2);
            Set<OFBundleFlags> flags = OFBundleFlagsSerializerVer14.readFrom(bb);
            OFMessage data = OFMessageVer14.READER.readFrom(bb);

            OFBundleAddMsgVer14 bundleAddMsgVer14 = new OFBundleAddMsgVer14(
                    xid,
                      bundleId,
                      flags,
                      data
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bundleAddMsgVer14);
            return bundleAddMsgVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBundleAddMsgVer14Funnel FUNNEL = new OFBundleAddMsgVer14Funnel();
    static class OFBundleAddMsgVer14Funnel implements Funnel<OFBundleAddMsgVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBundleAddMsgVer14 message, PrimitiveSink sink) {
            // fixed value property version = 5
            sink.putByte((byte) 0x5);
            // fixed value property type = 34
            sink.putByte((byte) 0x22);
            // FIXME: skip funnel of length
            sink.putLong(message.xid);
            message.bundleId.putTo(sink);
            // skip pad (2 bytes)
            OFBundleFlagsSerializerVer14.putTo(message.flags, sink);
            message.data.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBundleAddMsgVer14> {
        @Override
        public void write(ByteBuf bb, OFBundleAddMsgVer14 message) {
            int startIndex = bb.writerIndex();
            // fixed value property version = 5
            bb.writeByte((byte) 0x5);
            // fixed value property type = 34
            bb.writeByte((byte) 0x22);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            bb.writeInt(U32.t(message.xid));
            message.bundleId.write4Bytes(bb);
            // pad: 2 bytes
            bb.writeZero(2);
            OFBundleFlagsSerializerVer14.writeTo(bb, message.flags);
            message.data.writeTo(bb);

            // update length field
            int length = bb.writerIndex() - startIndex;
            if (length > MAXIMUM_LENGTH) {
                throw new IllegalArgumentException("OFBundleAddMsgVer14: message length (" + length + ") exceeds maximum (0xFFFF)");
            }
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBundleAddMsgVer14(");
        b.append("xid=").append(xid);
        b.append(", ");
        b.append("bundleId=").append(bundleId);
        b.append(", ");
        b.append("flags=").append(flags);
        b.append(", ");
        b.append("data=").append(data);
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
        OFBundleAddMsgVer14 other = (OFBundleAddMsgVer14) obj;

        if( xid != other.xid)
            return false;
        if (bundleId == null) {
            if (other.bundleId != null)
                return false;
        } else if (!bundleId.equals(other.bundleId))
            return false;
        if (flags == null) {
            if (other.flags != null)
                return false;
        } else if (!flags.equals(other.flags))
            return false;
        if (data == null) {
            if (other.data != null)
                return false;
        } else if (!data.equals(other.data))
            return false;
        return true;
    }

    @Override
    public boolean equalsIgnoreXid(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFBundleAddMsgVer14 other = (OFBundleAddMsgVer14) obj;

        // ignore XID
        if (bundleId == null) {
            if (other.bundleId != null)
                return false;
        } else if (!bundleId.equals(other.bundleId))
            return false;
        if (flags == null) {
            if (other.flags != null)
                return false;
        } else if (!flags.equals(other.flags))
            return false;
        if (data == null) {
            if (other.data != null)
                return false;
        } else if (!data.equals(other.data))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (xid ^ (xid >>> 32));
        result = prime * result + ((bundleId == null) ? 0 : bundleId.hashCode());
        result = prime * result + ((flags == null) ? 0 : flags.hashCode());
        result = prime * result + ((data == null) ? 0 : data.hashCode());
        return result;
    }

    @Override
    public int hashCodeIgnoreXid() {
        final int prime = 31;
        int result = 1;

        // ignore XID
        result = prime * result + ((bundleId == null) ? 0 : bundleId.hashCode());
        result = prime * result + ((flags == null) ? 0 : flags.hashCode());
        result = prime * result + ((data == null) ? 0 : data.hashCode());
        return result;
    }

}
